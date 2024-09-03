{
  "targets": [
    { 
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "include_dirs" : [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      "target_name": "testnapi",
      "sources": [ 
        "native_cpp/main.cpp",
        "native_cpp/hello_world.cpp",
        "native_cpp/simple_class.cpp",
        "native_cpp/wrapped_class.cpp",
        "native_cpp/converter.cpp"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      'libraries': [],
      'dependencies': [
        "<!(node -p \"require('node-addon-api').gyp\")"
      ],
    }
  ]
}