
#include <lockf2.h>

int lockf64(int fd, int cmd, off64_t length) {
  // Translate POSIX lockf into fcntl.
  struct flock64 fl;
  memset(&fl, 0, sizeof(fl));
  fl.l_whence = SEEK_CUR;
  fl.l_start = 0;
  fl.l_len = length;

  if (cmd == F_ULOCK) {
    fl.l_type = F_UNLCK;
    cmd = F_SETLK64;
    return fcntl(fd, F_SETLK64, &fl);
  }

  if (cmd == F_LOCK) {
    fl.l_type = F_WRLCK;
    return fcntl(fd, F_SETLKW64, &fl);
  }

  if (cmd == F_TLOCK) {
    fl.l_type = F_WRLCK;
    return fcntl(fd, F_SETLK64, &fl);
  }

  if (cmd == F_TEST) {
    fl.l_type = F_RDLCK;
    if (fcntl(fd, F_GETLK64, &fl) == -1) return -1;
    if (fl.l_type == F_UNLCK || fl.l_pid == getpid()) return 0;
    errno = EACCES;
    return -1;
  }

  errno = EINVAL;
  return -1;
}
