#define K8S_CONTAINER_VALID_LOCAL_RESOURCE_ID	"["		\
	"1591649196,"			\
	"{"				\
    "\"message\": \"K8S_CONTAINER_VALID_LOCAL_RESOURCE_ID\","		\
    "\"logging.googleapis.com/local_resource_id\": \"k8s_container.testnamespace.testpodname.testcontainername\","		\
	"\"key_0\": false,"		\
	"\"key_1\": true,"		\
	"\"key_2\": \"some string\","		\
	"\"key_3\": 0.12345678,"		\
	"\"key_4\": 5000,"		\
	"\"END_KEY\": \"JSON_END\""		\
	"}]"

#define K8S_CONTAINER_INVALID_JSON	"["		\
	"1591649196,"			\
	"{{{{"				\
    "\"message\": \"K8S_CONTAINER_VALID_LOCAL_RESOURCE_ID\","		\
    "\"logging.googleapis.com/local_resource_id\": \"k8s_container.testnamespace.testpodname.testcontainername\","		\
	"\"key_0\": false,"		\
	"\"key_1\": true,"		\
	"\"key_2\": \"some string\","		\
	"\"key_3\": 0.12345678,"		\
	"\"key_4\": 5000,"		\
	"\"END_KEY\": \"JSON_END\""		\
	"}]"


