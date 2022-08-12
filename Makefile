.PHONY: test build

cland: 
	bazel run @hedron_compile_commands//:refresh_all
test: cland
	bazel test --test_output=all //:lib-test

build-%: cland
	bazel build //:${*}
