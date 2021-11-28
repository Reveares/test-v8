# Automatically generated by scripts/boost/generate-ports.ps1

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/tokenizer
    REF boost-1.77.0
    SHA512 3e271ba5fd74ba532cb9fb37c9aabb2c37c7221d780dbcd20ac372109e8a93aae591b5bbdcf901325d3fa2e3bfb5f564601d9920397a78fe0a3a9efe58e992ad
    HEAD_REF master
)

include(${CURRENT_INSTALLED_DIR}/share/boost-vcpkg-helpers/boost-modular-headers.cmake)
boost_modular_headers(SOURCE_PATH ${SOURCE_PATH})