TODO
===

 1. main app - add list available config parsers
 1. main app - add list available spec parsers
 1. main app - make logging work
 1. main app - make lint, update, new commands work
 1. all config parsers: write php array spec, write php linter for spec
 1. config ini parser:
    1. handle errors in parse_ini_file with interim error handler
    1. check required/set default config items to match array spec
    1. write method to write out changed configuration

Far Future
===
 1. another app or flag for config generation
 1. spec parser for other formats
 1. another app or flag for scanner for other formats? gintrospection based scanner?

// 5. changes in behavior
//    3. actual output location for generation
//    4. logging behavior/location
// 6. do generation

set up writing
//       2. templates format and location
//       3. what to generate


//   3.a. new - writing
//     1. using spec data, write C files
//     2. using spec data, write test files
//     3. using spec data, write doc files
//   3.b. update - reading/writing
//     1. read in data, compare to spec data, write C files
//     2. read in data, compare to spec data, write test files
//     3. read in data, compare to spec data, write doc files