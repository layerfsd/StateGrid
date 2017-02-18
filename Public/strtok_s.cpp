#include "StdAfx.h"
#include <stdio.h>
#include "strtok_s.h"

/***
*tcstok_s.inl - implementation of strtok_s
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       This file contains the algorithm for strtok_s.
*
****/

#ifdef _UNICODE
wchar_t * wcstok_s(wchar_t *_String, const wchar_t *_Control, wchar_t **_Context)
{
    wchar_t *token;
    const wchar_t *ctl;

    /* validation section */
    //_VALIDATE_POINTER_ERROR_RETURN(_Context, EINVAL, NULL);
    //_VALIDATE_POINTER_ERROR_RETURN(_Control, EINVAL, NULL);
    //_VALIDATE_CONDITION_ERROR_RETURN(_String != NULL || *_Context != NULL, EINVAL, NULL);

    /* If string==NULL, continue with previous string */
    if (!_String)
    {
        _String = *_Context;
    }

    /* Find beginning of token (skip over leading delimiters). Note that
    * there is no token iff this loop sets string to point to the terminal null. */
    for ( ; *_String != 0 ; _String++)
    {
        for (ctl = _Control; *ctl != 0 && *ctl != *_String; ctl++)
            ;
        if (*ctl == 0)
        {
            break;
        }
    }

    token = _String;

    /* Find the end of the token. If it is not the end of the string,
    * put a null there. */
    for ( ; *_String != 0 ; _String++)
    {
        for (ctl = _Control; *ctl != 0 && *ctl != *_String; ctl++)
            ;
        if (*ctl != 0)
        {
            *_String++ = 0;
            break;
        }
    }

    /* Update the context */
    *_Context = _String;

    /* Determine if a token has been found. */
    if (token == _String)
    {
        return NULL;
    }
    else
    {
        return token;
    }
}
#else
char * strtok_s(char *_String, const char *_Control, char **_Context)
{
    unsigned char *str;
    const unsigned char *ctl = (const unsigned char *)_Control;
    unsigned char map[32];
    int count;

    /* Clear control map */
    for (count = 0; count < 32; count++)
    {
        map[count] = 0;
    }

    /* Set bits in delimiter table */
    do {
        map[*ctl >> 3] |= (1 << (*ctl & 7));
    } while (*ctl++);

    /* If string is NULL, set str to the saved
    * pointer (i.e., continue breaking tokens out of the string
    * from the last strtok call) */
    if (_String != NULL)
    {
        str = (unsigned char *)_String;
    }
    else
    {
        str = (unsigned char *)*_Context;
    }

    /* Find beginning of token (skip over leading delimiters). Note that
    * there is no token iff this loop sets str to point to the terminal
    * null (*str == 0) */
    while ((map[*str >> 3] & (1 << (*str & 7))) && *str != 0)
    {
        str++;
    }

    _String = (char *)str;

    /* Find the end of the token. If it is not the end of the string,
    * put a null there. */
    for ( ; *str != 0 ; str++ )
    {
        if (map[*str >> 3] & (1 << (*str & 7)))
        {
            *str++ = 0;
            break;
        }
    }

    /* Update context */
    *_Context = (char *)str;

    /* Determine if a token has been found. */
    if ((unsigned char *)_String == str)
    {
        return NULL;
    }
    else
    {
        return _String;
    }
}
#endif