.PHONY: test build

test:
	bazel test --test_output=all //:lib-test

build-%:
	bazel build //:${*}
