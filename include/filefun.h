#ifndef _FILEFUN_H_
#define _FILEFUN_H_

extern void CreateUserList(USER *head);

extern void AddNewUser(USER *head,char *s1,char *s2);

extern char *SearchAccounts(USER *head,char *string);

extern void freeUserlist(USER **head);
#endif