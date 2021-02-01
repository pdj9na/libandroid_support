#pragma once

#define SIG_CANCEL_SIGNAL SIGUSR1
#define PTHREAD_CANCEL_ENABLE 1
#define PTHREAD_CANCEL_DISABLE 0


int pthread_setcancelstate(int state, int *oldstate); // __INTRODUCED_IN(14);

#define pthread_cancel(thread) \
    pthread_kill(thread, SIG_CANCEL_SIGNAL)
