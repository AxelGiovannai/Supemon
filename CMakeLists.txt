cmake_minimum_required(VERSION 3.10)
project(SupemonAlpha)

set(SOURCES
    main.c
    fight.c
    supemon.c
    load_and_save.c
    player.c
    shop.c
    item.c
    utils.c
)

add_executable(Supemon ${SOURCES})