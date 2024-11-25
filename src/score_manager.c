/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** _
*/

#include "hunter.h"
#include "lib.h"
#include <SFML/Network.h>

int get_score(hunterinfo_t *hf)
{
    sfHttp *http = sfHttp_create();
    sfHttpRequest *req = sfHttpRequest_create();
    sfHttpResponse *res;
    sfTime timeout = (sfTime){ .microseconds = 0 };
    char const *body;

    sfHttpRequest_setMethod(req, sfHttpGet);
    sfHttpRequest_setUri(req, "/score");
    sfHttp_setHost(http, "http://localhost", 3000);
    res = sfHttp_sendRequest(http, req, timeout);
    body = sfHttpResponse_getBody(res);
    hf->high_score = my_getnbr(body);
    my_printf("%d\n", hf->high_score);
    return EXIT_SUCCESS;
}

int post_score(hunterinfo_t *hf)
{
    sfHttp *http = sfHttp_create();
    sfHttpRequest *req = sfHttpRequest_create();
    sfHttpResponse *res;
    sfTime timeout = (sfTime){ .microseconds = 0 };
    char score[10];
    char *uri = "/score?score=";
    char const *body;

    sfHttpRequest_setMethod(req, sfHttpPost);
    my_numstr(score, hf->score);
    sfHttpRequest_setUri(req, my_strcat(uri, score));
    sfHttpRequest_setBody(req, score);
    sfHttp_setHost(http, "http://localhost", 3000);
    res = sfHttp_sendRequest(http, req, timeout);
    body = sfHttpResponse_getBody(res);
    my_printf("%s\n", body);
    return EXIT_SUCCESS;
}
