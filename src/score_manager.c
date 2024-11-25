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
    sfTime timeout = (sfTime){ .microseconds = API_TIMEOUT };
    char const *body;

    sfHttpRequest_setMethod(req, sfHttpGet);
    sfHttpRequest_setUri(req, "/score");
    sfHttp_setHost(http, API_HOST, API_PORT);
    res = sfHttp_sendRequest(http, req, timeout);
    body = sfHttpResponse_getBody(res);
    hf->high_score = my_getnbr(body);
    my_printf("Get score from %s:%d\nAPI response: %d\n", API_HOST, API_PORT,
        hf->high_score);
    return EXIT_SUCCESS;
}

int post_score(hunterinfo_t *hf)
{
    sfHttp *http = sfHttp_create();
    sfHttpRequest *req = sfHttpRequest_create();
    sfHttpResponse *res;
    sfTime timeout = (sfTime){ .microseconds = API_TIMEOUT };
    char score[10];
    char *uri = "/score?score=";
    char const *body;

    sfHttpRequest_setMethod(req, sfHttpPost);
    my_numstr(score, hf->score);
    sfHttpRequest_setUri(req, my_strcat(uri, score));
    sfHttpRequest_setBody(req, score);
    sfHttp_setHost(http, API_HOST, API_PORT);
    res = sfHttp_sendRequest(http, req, timeout);
    body = sfHttpResponse_getBody(res);
    my_printf("Post score to %s:%d\nAPI response: %s\n", API_HOST, API_PORT,
        body);
    return EXIT_SUCCESS;
}
