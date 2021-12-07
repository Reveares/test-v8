#include "v8.h"
#include "libplatform/libplatform.h"
#include <iostream>

int main(int argc, char *argv[]) {
    // Init v8
    auto platform = v8::platform::NewDefaultPlatform();
    v8::V8::InitializePlatform(platform.get());
    v8::V8::Initialize();

    v8::Isolate::CreateParams create_params;
    create_params.array_buffer_allocator =
        v8::ArrayBuffer::Allocator::NewDefaultAllocator();
    auto* isolate = v8::Isolate::New(create_params);

    {
        v8::Isolate::Scope isolate_scope(isolate);
        v8::HandleScope handle_scope(isolate);

        auto local_context = v8::Context::New(isolate);
        v8::Context::Scope context_scope(local_context);

        // Compile and run script
        constexpr char script[] = "5 + 10";
        v8::Local<v8::String> source =
            v8::String::NewFromUtf8Literal(isolate, script);

        v8::Local<v8::Script> compiled_script =
            v8::Script::Compile(local_context, source).ToLocalChecked();

        auto result = compiled_script->Run(local_context);
        if (!result.IsEmpty()) {
            std::cout << "Got result: " << result.ToLocalChecked().As<v8::Int32>()->Value() << '\n';
        }
    }

    // Cleanup
    auto *allocator = isolate->GetArrayBufferAllocator();
    isolate->Dispose();
    v8::V8::Dispose();
    v8::V8::ShutdownPlatform();
    delete allocator;

    return 0;
}
