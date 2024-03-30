// hello.cc
#include <node.h>

void sum(const v8::FunctionCallbackInfo<v8::Value>& args) {
	v8::Isolate* isolate = args.GetIsolate();

	double a = 3.14, b = 200.10040324234;
	for (int i = 0; i < 10000000; i++) a += b;
	auto total = v8::Number::New(isolate, a);

	args.GetReturnValue().Set(total);
}

void Initialize(v8::Local<v8::Object> exports) {
	NODE_SET_METHOD(exports, "sum", sum);
}

NODE_MODULE()