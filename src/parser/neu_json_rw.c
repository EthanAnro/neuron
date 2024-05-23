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

#include <jansson.h>

#include "json/json.h"

#include "define.h"
#include "tag.h"

#include "json/neu_json_rw.h"

int neu_json_encode_read_resp(void *json_object, void *param)
{
    int                   ret  = 0;
    neu_json_read_resp_t *resp = (neu_json_read_resp_t *) param;

    void *                    tag_array = neu_json_array();
    neu_json_read_resp_tag_t *p_tag     = resp->tags;
    for (int i = 0; i < resp->n_tag; i++) {
        neu_json_elem_t tag_elems[2 + NEU_TAG_META_SIZE] = { 0 };

        tag_elems[0].name      = "name";
        tag_elems[0].t         = NEU_JSON_STR;
        tag_elems[0].v.val_str = p_tag->name;

        if (p_tag->error != 0) {
            tag_elems[1].name      = "error";
            tag_elems[1].t         = NEU_JSON_INT;
            tag_elems[1].v.val_int = p_tag->error;
        } else {
            tag_elems[1].name      = "value";
            tag_elems[1].t         = p_tag->t;
            tag_elems[1].v         = p_tag->value;
            tag_elems[1].precision = p_tag->precision;
        }

        for (int k = 0; k < p_tag->n_meta; k++) {
            tag_elems[2 + k].name = p_tag->metas[k].name;
            tag_elems[2 + k].t    = p_tag->metas[k].t;
            tag_elems[2 + k].v    = p_tag->metas[k].value;
        }

        tag_array =
            neu_json_encode_array(tag_array, tag_elems, 2 + p_tag->n_meta);
        p_tag++;
    }

    neu_json_elem_t resp_elems[] = { {
        .name         = "tags",
        .t            = NEU_JSON_OBJECT,
        .v.val_object = tag_array,
    } };
    ret = neu_json_encode_field(json_object, resp_elems,
                                NEU_JSON_ELEM_SIZE(resp_elems));

    return ret;
}

int neu_json_encode_read_resp1(void *json_object, void *param)
{
    int                   ret  = 0;
    neu_json_read_resp_t *resp = (neu_json_read_resp_t *) param;

    void *values = neu_json_encode_new();
    void *errors = neu_json_encode_new();
    void *metas  = neu_json_encode_new();

    neu_json_read_resp_tag_t *p_tag = resp->tags;
    for (int i = 0; i < resp->n_tag; i++) {
        neu_json_elem_t tag_elem = { 0 };

        if (p_tag->error == 0) {
            tag_elem.name      = p_tag->name;
            tag_elem.t         = p_tag->t;
            tag_elem.v         = p_tag->value;
            tag_elem.precision = p_tag->precision;
            neu_json_encode_field(values, &tag_elem, 1);
        } else {
            tag_elem.name      = p_tag->name;
            tag_elem.t         = NEU_JSON_INT;
            tag_elem.v.val_int = p_tag->error;
            neu_json_encode_field(errors, &tag_elem, 1);
        }

        if (p_tag->n_meta > 0) {
            void *meta = neu_json_encode_new();
            for (int k = 0; k < p_tag->n_meta; k++) {
                neu_json_elem_t meta_elem = { 0 };
                meta_elem.name            = p_tag->metas[k].name;
                meta_elem.t               = p_tag->metas[k].t;
                meta_elem.v               = p_tag->metas[k].value;
                neu_json_encode_field(meta, &meta_elem, 1);
            }

            neu_json_elem_t meta_elem = { 0 };
            meta_elem.name            = p_tag->name;
            meta_elem.t               = NEU_JSON_OBJECT;
            meta_elem.v.val_object    = meta;
            neu_json_encode_field(metas, &meta_elem, 1);
        }

        p_tag++;
    }

    neu_json_elem_t resp_elems[] = {
        {
            .name         = "values",
            .t            = NEU_JSON_OBJECT,
            .v.val_object = values,
        },
        {
            .name         = "errors",
            .t            = NEU_JSON_OBJECT,
            .v.val_object = errors,

        },
        {
            .name         = "metas",
            .t            = NEU_JSON_OBJECT,
            .v.val_object = metas,

        },
    };

    ret = neu_json_encode_field(json_object, resp_elems,
                                NEU_JSON_ELEM_SIZE(resp_elems));
    return ret;
}

int neu_json_decode_write_req(char *buf, neu_json_write_req_t **result)
{
    void *json_obj = neu_json_decode_new(buf);
    if (NULL == json_obj) {
        return -1;
    }

    int ret = neu_json_decode_write_req_json(json_obj, result);
    neu_json_decode_free(json_obj);
    return ret;
}

int decode_write_req_json(void *json_obj, neu_json_write_req_t *req)
{
    int ret = 0;

    neu_json_elem_t req_elems[] = {
        {
            .name = "node",
            .t    = NEU_JSON_STR,
        },
        {
            .name = "group",
            .t    = NEU_JSON_STR,
        },
        {
            .name = "tag",
            .t    = NEU_JSON_STR,
        },
        {
            .name = "value",
            .t    = NEU_JSON_VALUE,
        },
        {
            .name      = "precision",
            .t         = NEU_JSON_INT,
            .attribute = NEU_JSON_ATTRIBUTE_OPTIONAL,
        },
    };

    if (req_elems[4].v.val_int > 0) {
        req_elems[3].t = NEU_JSON_DOUBLE;
    }

    ret = neu_json_decode_by_json(json_obj, NEU_JSON_ELEM_SIZE(req_elems),
                                  req_elems);
    if (ret != 0) {
        goto error;
    }

    req->node  = req_elems[0].v.val_str;
    req->group = req_elems[1].v.val_str;
    req->tag   = req_elems[2].v.val_str;
    req->t     = req_elems[3].t;
    req->value = req_elems[3].v;

    return ret;

error:
    free(req_elems[0].v.val_str);
    free(req_elems[1].v.val_str);
    free(req_elems[2].v.val_str);
    return ret;
}

int neu_json_decode_write_req_json(void *                 json_obj,
                                   neu_json_write_req_t **result)
{
    neu_json_write_req_t *req = calloc(1, sizeof(neu_json_write_req_t));
    if (req == NULL) {
        return -1;
    }

    int ret = decode_write_req_json(json_obj, req);
    if (0 == ret) {
        *result = req;
    } else {
        free(req);
    }

    return ret;
}

void neu_json_decode_write_req_free(neu_json_write_req_t *req)
{
    free(req->group);
    free(req->node);
    free(req->tag);
    if (req->t == NEU_JSON_STR) {
        free(req->value.val_str);
    }
    if (req->t == NEU_JSON_BYTES && req->value.val_bytes.length > 0) {
        free(req->value.val_bytes.bytes);
    }

    free(req);
}

int neu_json_decode_write_tags_req(char *                      buf,
                                   neu_json_write_tags_req_t **result)
{
    void *json_obj = neu_json_decode_new(buf);
    if (NULL == json_obj) {
        return -1;
    }

    int ret = neu_json_decode_write_tags_req_json(json_obj, result);
    neu_json_decode_free(json_obj);
    return ret;
}

static int decode_write_tags_req_json(void *                     json_obj,
                                      neu_json_write_tags_req_t *req)
{
    int ret = 0;

    neu_json_elem_t req_elems[] = {
        {
            .name = "node",
            .t    = NEU_JSON_STR,
        },
        {
            .name = "group",
            .t    = NEU_JSON_STR,
        },
        {
            .name = "tags",
            .t    = NEU_JSON_OBJECT,
        },
    };
    ret = neu_json_decode_by_json(json_obj, NEU_JSON_ELEM_SIZE(req_elems),
                                  req_elems);
    if (ret != 0) {
        return -1;
    }

    req->node  = req_elems[0].v.val_str;
    req->group = req_elems[1].v.val_str;

    req->n_tag = neu_json_decode_array_size_by_json(json_obj, "tags");
    if (req->n_tag <= 0) {
        return -1;
    }

    req->tags = calloc(req->n_tag, sizeof(neu_json_write_tags_elem_t));
    for (int i = 0; i < req->n_tag; i++) {
        neu_json_elem_t v_elems[] = {
            {
                .name = "tag",
                .t    = NEU_JSON_STR,
            },
            {
                .name = "value",
                .t    = NEU_JSON_VALUE,
            },
        };

        ret = neu_json_decode_array_by_json(
            json_obj, "tags", i, NEU_JSON_ELEM_SIZE(v_elems), v_elems);
        req->tags[i].tag   = v_elems[0].v.val_str;
        req->tags[i].t     = v_elems[1].t;
        req->tags[i].value = v_elems[1].v;

        if (ret != 0) {
            for (; i >= 0; --i) {
                free(req->tags[i].tag);
                if (NEU_JSON_STR == req->tags[i].t) {
                    free(req->tags[i].value.val_str);
                }
            }
            free(req->node);
            free(req->group);
            free(req->tags);
            req->tags = NULL;
            return ret;
        }
    }

    return 0;
}

int neu_json_decode_write_tags_req_json(void *                      json_obj,
                                        neu_json_write_tags_req_t **result)
{
    neu_json_write_tags_req_t *req =
        calloc(1, sizeof(neu_json_write_tags_req_t));
    if (req == NULL) {
        return -1;
    }

    int ret = decode_write_tags_req_json(json_obj, req);
    if (0 == ret) {
        *result = req;
    } else {
        free(req);
    }

    return ret;
}

void neu_json_decode_write_tags_req_free(neu_json_write_tags_req_t *req)
{
    free(req->group);
    free(req->node);

    for (int i = 0; i < req->n_tag; i++) {
        free(req->tags[i].tag);
        if (req->tags[i].t == NEU_JSON_STR) {
            free(req->tags[i].value.val_str);
        }
        if (req->tags[i].t == NEU_JSON_BYTES &&
            req->tags[i].value.val_bytes.length > 0) {
            free(req->tags[i].value.val_bytes.bytes);
        }
    }
    free(req->tags);
    free(req);
}

int neu_json_decode_write(char *buf, neu_json_write_t **result)
{
    neu_json_write_t *req = calloc(1, sizeof(*req));
    if (NULL == req) {
        return -1;
    }

    void *json_obj = neu_json_decode_new(buf);
    if (NULL == json_obj) {
        free(req);
        return -1;
    }

    int ret = 0;
    if (NULL == json_object_get(json_obj, "tags")) {
        req->singular = true;
        ret           = decode_write_req_json(json_obj, &req->single);
    } else {
        req->singular = false;
        ret           = decode_write_tags_req_json(json_obj, &req->plural);
    }

    if (0 == ret) {
        *result = req;
    } else {
        free(req);
    }

    neu_json_decode_free(json_obj);
    return ret;
}

void neu_json_decode_write_free(neu_json_write_t *req)
{
    if (req) {
        if (req->singular) {
            neu_json_decode_write_req_free((neu_json_write_req_t *) req);
        } else {
            neu_json_decode_write_tags_req_free(
                (neu_json_write_tags_req_t *) req);
        }
    }
}

int neu_json_decode_read_req(char *buf, neu_json_read_req_t **result)
{
    int   ret      = 0;
    void *json_obj = NULL;

    json_obj = neu_json_decode_new(buf);
    if (NULL == json_obj) {
        return -1;
    }

    neu_json_read_req_t *req = calloc(1, sizeof(neu_json_read_req_t));
    if (req == NULL) {
        neu_json_decode_free(json_obj);
        return -1;
    }

    neu_json_elem_t req_elems[] = {
        {
            .name = "node",
            .t    = NEU_JSON_STR,
        },
        {
            .name = "group",
            .t    = NEU_JSON_STR,
        },
        {
            .name      = "sync",
            .t         = NEU_JSON_BOOL,
            .attribute = NEU_JSON_ATTRIBUTE_OPTIONAL,
        },
        {
            .name      = "query",
            .t         = NEU_JSON_OBJECT,
            .attribute = NEU_JSON_ATTRIBUTE_OPTIONAL,
        },
    };

    neu_json_elem_t query_elems[] = {
        {
            .name      = "name",
            .t         = NEU_JSON_STR,
            .attribute = NEU_JSON_ATTRIBUTE_OPTIONAL,
        },
        {
            .name      = "description",
            .t         = NEU_JSON_STR,
            .attribute = NEU_JSON_ATTRIBUTE_OPTIONAL,
        },
    };

    ret = neu_json_decode_by_json(json_obj, NEU_JSON_ELEM_SIZE(req_elems),
                                  req_elems);
    if (ret != 0) {
        goto error;
    }

    req->node  = req_elems[0].v.val_str;
    req->group = req_elems[1].v.val_str;
    req->sync  = req_elems[2].v.val_bool;

    if (req_elems[3].v.val_object) {
        ret = neu_json_decode_by_json(req_elems[3].v.val_object,
                                      NEU_JSON_ELEM_SIZE(query_elems),
                                      query_elems);
        if (ret != 0) {
            goto error;
        }
        req->name = query_elems[0].v.val_str;
        req->desc = query_elems[1].v.val_str;
    }

    *result = req;
    neu_json_decode_free(json_obj);
    return ret;

error:
    free(query_elems[0].v.val_str);
    free(query_elems[1].v.val_str);
    free(req_elems[0].v.val_str);
    free(req_elems[1].v.val_str);
    free(req);
    if (json_obj != NULL) {
        neu_json_decode_free(json_obj);
    }
    return ret;
}

void neu_json_decode_read_req_free(neu_json_read_req_t *req)
{
    free(req->group);
    free(req->node);

    free(req);
}

int neu_json_encode_read_periodic_resp(void *json_object, void *param)
{
    int                       ret  = 0;
    neu_json_read_periodic_t *resp = (neu_json_read_periodic_t *) param;

    neu_json_elem_t resp_elems[] = { {
                                         .name      = "node",
                                         .t         = NEU_JSON_STR,
                                         .v.val_str = resp->node,
                                     },
                                     {
                                         .name      = "group",
                                         .t         = NEU_JSON_STR,
                                         .v.val_str = resp->group,
                                     },
                                     {
                                         .name      = "timestamp",
                                         .t         = NEU_JSON_INT,
                                         .v.val_int = resp->timestamp,
                                     } };
    ret = neu_json_encode_field(json_object, resp_elems,
                                NEU_JSON_ELEM_SIZE(resp_elems));

    return ret;
}

void neu_json_metas_to_json(neu_tag_meta_t *metas, int n_meta,
                            neu_json_read_resp_tag_t *json_tag)
{
    for (int k = 0; k < n_meta; k++) {
        if (strlen(metas[k].name) > 0) {
            json_tag->metas[k].name = metas[k].name;
            switch (metas[k].value.type) {
            case NEU_TYPE_UINT8:
                json_tag->metas[k].t             = NEU_JSON_INT;
                json_tag->metas[k].value.val_int = metas[k].value.value.u8;
                break;
            case NEU_TYPE_INT8:
                json_tag->metas[k].t             = NEU_JSON_INT;
                json_tag->metas[k].value.val_int = metas[k].value.value.i8;
                break;
            case NEU_TYPE_INT16:
                json_tag->metas[k].t             = NEU_JSON_INT;
                json_tag->metas[k].value.val_int = metas[k].value.value.i16;
                break;
            case NEU_TYPE_INT32:
                json_tag->metas[k].t             = NEU_JSON_INT;
                json_tag->metas[k].value.val_int = metas[k].value.value.i32;
                break;
            case NEU_TYPE_INT64:
                json_tag->metas[k].t             = NEU_JSON_INT;
                json_tag->metas[k].value.val_int = metas[k].value.value.i64;
                break;
            case NEU_TYPE_WORD:
            case NEU_TYPE_UINT16:
                json_tag->metas[k].t             = NEU_JSON_INT;
                json_tag->metas[k].value.val_int = metas[k].value.value.u16;
                break;
            case NEU_TYPE_DWORD:
            case NEU_TYPE_UINT32:
                json_tag->metas[k].t             = NEU_JSON_INT;
                json_tag->metas[k].value.val_int = metas[k].value.value.u32;
                break;
            case NEU_TYPE_LWORD:
            case NEU_TYPE_UINT64:
                json_tag->metas[k].t             = NEU_JSON_INT;
                json_tag->metas[k].value.val_int = metas[k].value.value.u64;
                break;
            case NEU_TYPE_FLOAT:
                json_tag->metas[k].t               = NEU_JSON_FLOAT;
                json_tag->metas[k].value.val_float = metas[k].value.value.f32;
                break;
            case NEU_TYPE_DOUBLE:
                json_tag->metas[k].t                = NEU_JSON_DOUBLE;
                json_tag->metas[k].value.val_double = metas[k].value.value.d64;
                break;
            case NEU_TYPE_BOOL:
                json_tag->metas[k].t = NEU_JSON_BOOL;
                json_tag->metas[k].value.val_bool =
                    metas[k].value.value.boolean;
                break;
            case NEU_TYPE_BIT:
                json_tag->metas[k].t             = NEU_JSON_BIT;
                json_tag->metas[k].value.val_bit = metas[k].value.value.u8;
                break;
            case NEU_TYPE_STRING:
            case NEU_TYPE_TIME:
            case NEU_TYPE_DATA_AND_TIME:
                json_tag->metas[k].t             = NEU_JSON_STR;
                json_tag->metas[k].value.val_str = metas[k].value.value.str;
                break;
            default:
                break;
            }
        } else {
            break;
        }
    }
}

int neu_json_decode_write_gtags_req(char *                       buf,
                                    neu_json_write_gtags_req_t **result)
{
    void *json_obj = neu_json_decode_new(buf);
    if (NULL == json_obj) {
        return -1;
    }

    int ret = neu_json_decode_write_gtags_req_json(json_obj, result);
    neu_json_decode_free(json_obj);
    return ret;
}

#include "utils/log.h"

static int decode_write_gtags_req_json(void *                      json_obj,
                                       neu_json_write_gtags_req_t *req)
{
    int ret = 0;

    neu_json_elem_t req_elems[] = {
        {
            .name = "node",
            .t    = NEU_JSON_STR,
        },
        {
            .name = "groups",
            .t    = NEU_JSON_OBJECT,
        },
    };
    ret = neu_json_decode_by_json(json_obj, NEU_JSON_ELEM_SIZE(req_elems),
                                  req_elems);
    if (ret != 0) {
        return -1;
    }

    req->node = req_elems[0].v.val_str;

    req->n_group = neu_json_decode_array_size_by_json(json_obj, "groups");
    if (req->n_group <= 0) {
        return -1;
    }

    req->groups = calloc(req->n_group, sizeof(neu_json_write_gtags_elem_t));
    for (int i = 0; i < req->n_group; i++) {
        neu_json_elem_t g_elems[] = {
            {
                .name = "group",
                .t    = NEU_JSON_STR,
            },
            {
                .name = "tags",
                .t    = NEU_JSON_OBJECT,
            },
        };

        ret = neu_json_decode_array_by_json(
            json_obj, "groups", i, NEU_JSON_ELEM_SIZE(g_elems), g_elems);

        req->groups[i].group = g_elems[0].v.val_str;
        req->groups[i].n_tag = json_array_size(g_elems[1].v.val_object);
        if (req->groups[i].n_tag <= 0) {
            continue;
        }

        req->groups[i].tags =
            calloc(req->groups[i].n_tag, sizeof(neu_json_write_tags_elem_t));

        for (int k = 0; k < req->groups[i].n_tag; k++) {
            neu_json_elem_t v_elems[] = {
                {
                    .name = "tag",
                    .t    = NEU_JSON_STR,
                },
                {
                    .name = "value",
                    .t    = NEU_JSON_VALUE,
                },
            };

            ret = neu_json_decode_array_elem(g_elems[1].v.val_object, k,
                                             NEU_JSON_ELEM_SIZE(v_elems),
                                             v_elems);
            if (ret != 0) {
                for (int x = i; x >= 0; x--) {
                    free(req->groups[x].tags);
                }
                free(req->groups);
                return -1;
            }
            req->groups[i].tags[k].tag   = v_elems[0].v.val_str;
            req->groups[i].tags[k].t     = v_elems[1].t;
            req->groups[i].tags[k].value = v_elems[1].v;
        }
    }

    return 0;
}

int neu_json_decode_write_gtags_req_json(void *                       json_obj,
                                         neu_json_write_gtags_req_t **result)
{
    neu_json_write_gtags_req_t *req =
        calloc(1, sizeof(neu_json_write_gtags_req_t));
    if (req == NULL) {
        return -1;
    }

    int ret = decode_write_gtags_req_json(json_obj, req);
    if (0 == ret) {
        *result = req;
    } else {
        free(req);
    }

    return ret;
}

void neu_json_decode_write_gtags_req_free(neu_json_write_gtags_req_t *req)
{
    free(req->node);

    for (int i = 0; i < req->n_group; i++) {
        free(req->groups[i].group);

        for (int k = 0; k < req->groups[i].n_tag; k++) {
            free(req->groups[i].tags[k].tag);

            if (req->groups[i].tags[k].t == NEU_JSON_STR) {
                free(req->groups[i].tags[k].value.val_str);
            }
            if (req->groups[i].tags[k].t == NEU_JSON_BYTES &&
                req->groups[i].tags[k].value.val_bytes.length > 0) {
                free(req->groups[i].tags[k].value.val_bytes.bytes);
            }
        }
        if (req->groups[i].n_tag > 0) {
            free(req->groups[i].tags);
        }
    }

    free(req->groups);
    free(req);
}
