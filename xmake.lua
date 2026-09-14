add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})

add_requires("raylib")

target("test")
    set_kind("binary")
    add_includedirs("src")
    add_files("src/**.cpp")
    add_packages("raylib")
    set_languages("c++26")
