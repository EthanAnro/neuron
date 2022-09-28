/**
 * NEURON IIoT System for Industry 4.0
 * Copyright (C) 2020-2022 EMQ Technologies Co., Ltd All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 **/

/*
 * DO NOT EDIT THIS FILE MANUALLY!
 * It was automatically generated by `json-autotype`.
 */

#include <stdlib.h>
#include <string.h>

#include "json/json.h"

#include "adapter.h"
#include "neu_json_node.h"

int neu_json_decode_add_node_req(char *buf, neu_json_add_node_req_t **result)
{
    int                      ret      = 0;
    void *                   json_obj = NULL;
    neu_json_add_node_req_t *req = calloc(1, sizeof(neu_json_add_node_req_t));
    if (req == NULL) {
        return -1;
    }

    json_obj = neu_json_decode_new(buf);

    neu_json_elem_t req_elems[] = { {
                                        .name = "plugin",
                                        .t    = NEU_JSON_STR,
                                    },
                                    {
                                        .name = "name",
                                        .t    = NEU_JSON_STR,
                                    } };
    ret = neu_json_decode_by_json(json_obj, NEU_JSON_ELEM_SIZE(req_elems),
                                  req_elems);
    if (ret != 0) {
        goto decode_fail;
    }

    req->plugin = req_elems[0].v.val_str;
    req->name   = req_elems[1].v.val_str;

    *result = req;
    goto decode_exit;

decode_fail:
    free(req);
    ret = -1;

decode_exit:
    if (json_obj != NULL) {
        neu_json_decode_free(json_obj);
    }
    return ret;
}

void neu_json_decode_add_node_req_free(neu_json_add_node_req_t *req)
{

    free(req->plugin);
    free(req->name);

    free(req);
}

int neu_json_decode_del_node_req(char *buf, neu_json_del_node_req_t **result)
{
    int                      ret      = 0;
    void *                   json_obj = NULL;
    neu_json_del_node_req_t *req = calloc(1, sizeof(neu_json_del_node_req_t));
    if (req == NULL) {
        return -1;
    }

    json_obj = neu_json_decode_new(buf);

    neu_json_elem_t req_elems[] = { {
        .name = "name",
        .t    = NEU_JSON_STR,
    } };
    ret = neu_json_decode_by_json(json_obj, NEU_JSON_ELEM_SIZE(req_elems),
                                  req_elems);
    if (ret != 0) {
        goto decode_fail;
    }

    req->name = req_elems[0].v.val_str;

    *result = req;
    goto decode_exit;

decode_fail:
    free(req);
    ret = -1;

decode_exit:
    if (json_obj != NULL) {
        neu_json_decode_free(json_obj);
    }
    return ret;
}

void neu_json_decode_del_node_req_free(neu_json_del_node_req_t *req)
{
    free(req->name);
    free(req);
}

int neu_json_encode_get_node_stat_resp(void *json_object, void *param)
{
    int                            ret = 0;
    neu_json_get_node_stat_resp_t *resp =
        (neu_json_get_node_stat_resp_t *) param;

    for (int i = 0; i < NEU_NODE_STAT_MAX; ++i) {
        if (i >= NEU_NODE_STAT_TAG_TOT_CNT &&
            NEU_NA_TYPE_DRIVER != resp->type) {
            // not a driver node, filter out driver specific counters
            break;
        }

        neu_json_elem_t resp_elems[] = {
            {
                .name      = (char *) neu_node_stat_string(i),
                .t         = NEU_JSON_INT,
                .v.val_int = resp->data[i],
            },
        };
        ret = neu_json_encode_field(json_object, resp_elems,
                                    NEU_JSON_ELEM_SIZE(resp_elems));
    }

    return ret;
}

int neu_json_encode_get_node_state_resp(void *json_object, void *param)
{
    int                             ret = 0;
    neu_json_get_node_state_resp_t *resp =
        (neu_json_get_node_state_resp_t *) param;

    neu_json_elem_t resp_elems[] = { {
                                         .name      = "running",
                                         .t         = NEU_JSON_INT,
                                         .v.val_int = resp->running,
                                     },
                                     {
                                         .name      = "link",
                                         .t         = NEU_JSON_INT,
                                         .v.val_int = resp->link,
                                     },
                                     {
                                         .name      = "average_rtt",
                                         .t         = NEU_JSON_INT,
                                         .v.val_int = resp->avg_rtt,
                                     } };
    ret = neu_json_encode_field(json_object, resp_elems,
                                NEU_JSON_ELEM_SIZE(resp_elems));

    return ret;
}

int neu_json_encode_get_nodes_state_resp(void *json_object, void *param)
{
    int                              ret = 0;
    neu_json_get_nodes_state_resp_t *resp =
        (neu_json_get_nodes_state_resp_t *) param;

    void *                      node_array = neu_json_array();
    neu_json_get_nodes_state_t *p_node     = resp->nodes;
    for (int i = 0; i < resp->n_node; i++) {
        neu_json_elem_t node_elems[] = {
            {
                .name      = "node",
                .t         = NEU_JSON_STR,
                .v.val_str = p_node->name,
            },
            {
                .name      = "running",
                .t         = NEU_JSON_INT,
                .v.val_int = p_node->running,
            },
            {
                .name      = "link",
                .t         = NEU_JSON_INT,
                .v.val_int = p_node->link,
            },
            {
                .name      = "average_rtt",
                .t         = NEU_JSON_INT,
                .v.val_int = p_node->avg_rtt,
            },
        };
        node_array = neu_json_encode_array(node_array, node_elems,
                                           NEU_JSON_ELEM_SIZE(node_elems));
        p_node++;
    }

    neu_json_elem_t resp_elems[] = { {
        .name         = "states",
        .t            = NEU_JSON_OBJECT,
        .v.val_object = node_array,
    } };
    ret = neu_json_encode_field(json_object, resp_elems,
                                NEU_JSON_ELEM_SIZE(resp_elems));

    return ret;
}

int neu_json_encode_get_nodes_resp(void *json_object, void *param)
{
    int                        ret  = 0;
    neu_json_get_nodes_resp_t *resp = (neu_json_get_nodes_resp_t *) param;

    void *                          node_array = neu_json_array();
    neu_json_get_nodes_resp_node_t *p_node     = resp->nodes;
    for (int i = 0; i < resp->n_node; i++) {
        neu_json_elem_t node_elems[] = {
            {
                .name      = "plugin",
                .t         = NEU_JSON_STR,
                .v.val_str = p_node->plugin,
            },
            {
                .name      = "name",
                .t         = NEU_JSON_STR,
                .v.val_str = p_node->name,
            },
        };
        node_array = neu_json_encode_array(node_array, node_elems,
                                           NEU_JSON_ELEM_SIZE(node_elems));
        p_node++;
    }

    neu_json_elem_t resp_elems[] = { {
        .name         = "nodes",
        .t            = NEU_JSON_OBJECT,
        .v.val_object = node_array,
    } };
    ret = neu_json_encode_field(json_object, resp_elems,
                                NEU_JSON_ELEM_SIZE(resp_elems));

    return ret;
}

int neu_json_decode_update_node_req(char *                       buf,
                                    neu_json_update_node_req_t **result)
{
    int                         ret      = 0;
    void *                      json_obj = NULL;
    neu_json_update_node_req_t *req =
        calloc(1, sizeof(neu_json_update_node_req_t));
    if (req == NULL) {
        return -1;
    }

    json_obj = neu_json_decode_new(buf);

    neu_json_elem_t req_elems[] = { {
                                        .name = "name",
                                        .t    = NEU_JSON_STR,
                                    },
                                    {
                                        .name = "id",
                                        .t    = NEU_JSON_INT,
                                    } };
    ret = neu_json_decode_by_json(json_obj, NEU_JSON_ELEM_SIZE(req_elems),
                                  req_elems);
    if (ret != 0) {
        goto decode_fail;
    }

    req->name = req_elems[0].v.val_str;
    req->id   = req_elems[1].v.val_int;

    *result = req;
    goto decode_exit;

decode_fail:
    free(req);
    ret = -1;

decode_exit:
    if (json_obj != NULL) {
        neu_json_decode_free(json_obj);
    }
    return ret;
}

void neu_json_decode_update_node_req_free(neu_json_update_node_req_t *req)
{

    free(req->name);

    free(req);
}

int neu_json_decode_node_ctl_req(char *buf, neu_json_node_ctl_req_t **result)
{
    int                      ret      = 0;
    void *                   json_obj = NULL;
    neu_json_node_ctl_req_t *req = calloc(1, sizeof(neu_json_node_ctl_req_t));
    if (req == NULL) {
        return -1;
    }

    json_obj = neu_json_decode_new(buf);

    neu_json_elem_t req_elems[] = { {
                                        .name = "node",
                                        .t    = NEU_JSON_STR,
                                    },
                                    {
                                        .name = "cmd",
                                        .t    = NEU_JSON_INT,
                                    } };
    ret = neu_json_decode_by_json(json_obj, NEU_JSON_ELEM_SIZE(req_elems),
                                  req_elems);
    if (ret != 0) {
        goto decode_fail;
    }

    req->node = req_elems[0].v.val_str;
    req->cmd  = req_elems[1].v.val_int;

    *result = req;
    goto decode_exit;

decode_fail:
    free(req);
    ret = -1;

decode_exit:
    if (json_obj != NULL) {
        neu_json_decode_free(json_obj);
    }
    return ret;
}

void neu_json_decode_node_ctl_req_free(neu_json_node_ctl_req_t *req)
{
    free(req->node);
    free(req);
}

int neu_json_decode_node_setting_req(char *                        buf,
                                     neu_json_node_setting_req_t **result)
{
    int                          ret      = 0;
    void *                       json_obj = NULL;
    neu_json_node_setting_req_t *req =
        calloc(1, sizeof(neu_json_node_setting_req_t));
    if (req == NULL) {
        return -1;
    }

    json_obj = neu_json_decode_new(buf);

    neu_json_elem_t req_elems[] = { {
        .name = "node",
        .t    = NEU_JSON_STR,
    } };
    ret = neu_json_decode_by_json(json_obj, NEU_JSON_ELEM_SIZE(req_elems),
                                  req_elems);
    if (ret != 0) {
        goto decode_fail;
    }

    req->node = req_elems[0].v.val_str;

    *result = req;
    goto decode_exit;

decode_fail:
    free(req);
    ret = -1;

decode_exit:
    if (json_obj != NULL) {
        neu_json_decode_free(json_obj);
    }
    return ret;
}

void neu_json_decode_node_setting_req_free(neu_json_node_setting_req_t *req)
{
    free(req->node);
    free(req);
}
