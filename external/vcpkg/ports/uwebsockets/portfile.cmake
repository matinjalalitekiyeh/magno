# header-only library
vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO uNetworking/uWebSockets
    REF 654b4558a4347cc9f437f82c6000639af5f20c2c  #v20.30.0
    SHA512 89e1b5c6e62f09fdd5974491ac607ac96d3afcdc30c1bfc52cfd92945e884fb892904c007df67ec64500197fc36745b94c365d076461ce4daa4df208226b82b1
    HEAD_REF master
)

file(COPY "${SOURCE_PATH}/src"  DESTINATION "${CURRENT_PACKAGES_DIR}/include")
file(RENAME "${CURRENT_PACKAGES_DIR}/include/src" "${CURRENT_PACKAGES_DIR}/include/uwebsockets")

file(INSTALL "${SOURCE_PATH}/LICENSE" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}" RENAME copyright)