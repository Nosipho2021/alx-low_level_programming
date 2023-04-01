* lists.h: Header file containing definitions and prototypes for all types and functions
Type / File	Definition / Prototype
* struct list _ s		•	char * str
* unsigned int _ len
* struct list _ s * next
typedef list _ t	struct list _ s
0 - print _ list.c	size _ t print _ list(const list_t * h);
1 - list _ len.c	size _ t list _ len(const list_t * h);
2 - add _ node.c	list _ t *add _ node(list _ t ** head, const char * str);
3 - add _ nod e _ end.c	list _ t *add _ node _ end(list _ t ** head, const char * str);
4 - free _ list.c	void free _ list(list _ t * head)
