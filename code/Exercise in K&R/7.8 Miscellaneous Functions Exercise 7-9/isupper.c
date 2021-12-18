
/* isupper: return 1 (true) if c is an upper case letter */
int isupper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}

#define ISUPPER(c) ((c) >= 'A' && (c) <= 'Z') ? 1 : 0

char *p = "This is a string";

if(ISUPPER(*p++))
    ;

((*p++) >= 'A' && (*p++) <= 'Z') ? 1 : 0

//increment the pointer p twice

if (ISUPPER(*p))
    ;
p++;




