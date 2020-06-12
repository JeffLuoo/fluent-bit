#include <fluent-bit.h>
#include "flb_tests_runtime.h"

/* Test data */
#include "data/stackdriver_test/k8s_container_test_cases.h"
#include "data/stackdriver_test/k8s_pod_test_cases.h"

/* Test functions */
void k8s_container_valid_local_resource_id(void);
void k8s_container_invalid_json(void);

void k8s_pod_valid_local_resource_id(void);
void k8s_pod_invalid_json(void);

/* Test list */
TEST_LIST = {
    {"k8s_container: payload has valid field local_resource_id: ",  k8s_container_valid_local_resource_id},
    {"k8s_container: payload format is not in json: ",  k8s_container_invalid_json},

    {"k8s_pod: payload has valid field local_resource_id: ",  k8s_pod_valid_local_resource_id},
    {"k8s_pod: payload format is not in json: ",  k8s_pod_invalid_json},

    {NULL, NULL}
};

void k8s_container_valid_local_resource_id(void) {
    int ret;
    int size = sizeof(K8S_CONTAINER_VALID_LOCAL_RESOURCE_ID) - 1;
    flb_ctx_t *ctx;
    int in_ffd;
    int out_ffd;

    ctx = flb_create();
    TEST_CHECK(ctx != NULL);
    flb_service_set(ctx, "Flush", "1", "Daemon", "off", "Log_Level", "info", NULL);

    in_ffd = flb_input(ctx, (char *) "lib", NULL);
    TEST_CHECK(in_ffd >= 0);
    flb_input_set(ctx, in_ffd, "tag", "k8s_container_test", NULL);

    out_ffd = flb_output(ctx, (char *) "stackdriver", NULL);
    TEST_CHECK(out_ffd >= 0);

    flb_output_set(ctx, out_ffd, "Match", "*", "resource", "k8s_container", 
                   "k8s_cluster_name", "k8s_cluster_name_test",
                   "k8s_cluster_location", "k8s_cluster_location_test", NULL);

    ret = flb_start(ctx);
    TEST_CHECK(ret == 0);

    flb_lib_push(ctx, in_ffd, (char *) K8S_CONTAINER_VALID_LOCAL_RESOURCE_ID, size);
    sleep(1); /* waiting flush */

    flb_stop(ctx);
    flb_destroy(ctx);
}

void k8s_container_invalid_json(void) {
    int ret;
    int size = sizeof(K8S_CONTAINER_INVALID_JSON) - 1;
    flb_ctx_t *ctx;
    int in_ffd;
    int out_ffd;

    ctx = flb_create();
    TEST_CHECK(ctx != NULL);
    flb_service_set(ctx, "Flush", "1", "Daemon", "off", "Log_Level", "info", NULL);

    in_ffd = flb_input(ctx, (char *) "lib", NULL);
    TEST_CHECK(in_ffd >= 0);
    flb_input_set(ctx, in_ffd, "tag", "k8s_container_test", NULL);

    out_ffd = flb_output(ctx, (char *) "stackdriver", NULL);
    TEST_CHECK(out_ffd >= 0);
    flb_output_set(ctx, out_ffd, "Match", "*", "resource", "k8s_container", 
                   "k8s_cluster_name", "k8s_cluster_name_test",
                   "k8s_cluster_location", "k8s_cluster_location_test", NULL);

    ret = flb_start(ctx);
    TEST_CHECK(ret == 0);

    flb_lib_push(ctx, in_ffd, (char *) K8S_CONTAINER_INVALID_JSON, size);
    sleep(1); /* waiting flush */

    flb_stop(ctx);
    flb_destroy(ctx);
}

void k8s_pod_valid_local_resource_id(void) {
    int ret;
    int size = sizeof(K8S_POD_VALID_LOCAL_RESOURCE_ID) - 1;
    flb_ctx_t *ctx;
    int in_ffd;
    int out_ffd;

    ctx = flb_create();
    TEST_CHECK(ctx != NULL);
    flb_service_set(ctx, "Flush", "1", "Daemon", "off", "Log_Level", "info", NULL);

    in_ffd = flb_input(ctx, (char *) "lib", NULL);
    TEST_CHECK(in_ffd >= 0);
    flb_input_set(ctx, in_ffd, "tag", "k8s_pod_test", NULL);

    out_ffd = flb_output(ctx, (char *) "stackdriver", NULL);
    TEST_CHECK(out_ffd >= 0);

    flb_output_set(ctx, out_ffd, "Match", "*", "resource", "k8s_pod", 
                   "k8s_cluster_name", "k8s_cluster_name_test",
                   "k8s_cluster_location", "k8s_cluster_location_test", NULL);

    ret = flb_start(ctx);
    TEST_CHECK(ret == 0);

    flb_lib_push(ctx, in_ffd, (char *) K8S_POD_VALID_LOCAL_RESOURCE_ID, size);
    sleep(1); /* waiting flush */

    flb_stop(ctx);
    flb_destroy(ctx);
}

void k8s_pod_invalid_json(void) {
    int ret;
    int size = sizeof(K8S_POD_INVALID_JSON) - 1;
    flb_ctx_t *ctx;
    int in_ffd;
    int out_ffd;

    ctx = flb_create();
    TEST_CHECK(ctx != NULL);
    flb_service_set(ctx, "Flush", "1", "Daemon", "off", "Log_Level", "info", NULL);

    in_ffd = flb_input(ctx, (char *) "lib", NULL);
    TEST_CHECK(in_ffd >= 0);
    flb_input_set(ctx, in_ffd, "tag", "k8s_pod_test", NULL);

    out_ffd = flb_output(ctx, (char *) "stackdriver", NULL);
    TEST_CHECK(out_ffd >= 0);
    flb_output_set(ctx, out_ffd, "Match", "*", "resource", "k8s_pod", 
                   "k8s_cluster_name", "k8s_cluster_name_test",
                   "k8s_cluster_location", "k8s_cluster_location_test", NULL);

    ret = flb_start(ctx);
    TEST_CHECK(ret == 0);

    flb_lib_push(ctx, in_ffd, (char *) K8S_POD_INVALID_JSON, size);
    sleep(1); /* waiting flush */

    flb_stop(ctx);
    flb_destroy(ctx);
}
