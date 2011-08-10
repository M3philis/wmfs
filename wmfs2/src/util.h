/*
 *  wmfs2 by Martin Duquesnoy <xorg62@gmail.com> { for(i = 2011; i < 2111; ++i) ©(i); }
 *  For license, see COPYING.
 */

#ifndef UTIL_H
#define UTIL_H

#include "wmfs.h"

/* Todo FREE_LIST(type, head, function_remove) */
#define FREE_LIST(type, head)                   \
     do {                                       \
          type *t;                              \
          while(!SLIST_EMPTY(&head)) {          \
               t = SLIST_FIRST(&head);          \
               SLIST_REMOVE_HEAD(&head, next);  \
               free(t); /* function_remove(t)*/ \
          }                                     \
     } while(/* CONSTCOND */ 0);

#define ATOM(a)  XInternAtom(W->dpy, (a), False)

void *xmalloc(size_t nmemb, size_t size);
void *xcalloc(size_t nmemb, size_t size);
int xasprintf(char **strp, const char *fmt, ...);
pid_t spawn(const char *format, ...);

#endif /* UTIL_H */