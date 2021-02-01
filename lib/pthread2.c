
#include <pthread2.h>
#include <signal.h>

int pthread_setcancelstate(int state, int *oldstate)
{
    sigset_t new, old;
    int ret;
    sigemptyset(&new);
    sigaddset(&new, SIG_CANCEL_SIGNAL);

    ret = pthread_sigmask(state == PTHREAD_CANCEL_ENABLE ? SIG_BLOCK : SIG_UNBLOCK, &new, &old);
    if (oldstate)
        *oldstate = sigismember(&old, SIG_CANCEL_SIGNAL) == 0 ? PTHREAD_CANCEL_DISABLE : PTHREAD_CANCEL_ENABLE;
    return ret;
}
