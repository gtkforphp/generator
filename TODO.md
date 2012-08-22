TODO
===

 1. all config parsers: write php array spec, write php linter for spec
 1. config ini parser:
    1. handle errors in parse_ini_file with interim error handler
    1. check required/set default config items to match array spec
    1. write method to write out changed configuration

add messages for normal and verbose modes (with shush up)

// 3. list available parsers for config
// 4. list available formats for specifications
// 5. lint config
// 6. lint specification
// 6.a. config and/or spec generation?
// 5. changes in behavior
//    1. overall "quiet" tag shuts ALL up (except fatals, see above)
//    2. overall "verbose" makes REALLY loud - can't do both!
//    3. actual output location for generation
//    4. logging behavior/location
//    5. update existing or new generation switch
//    6. generate ext, tests, doc
// 6. do generation
//    1. parse configuration
//     1. choose and load parser format
//     2. parse into array/load
//     3. format check
//     4.setup specification
//       1. spec format and location
//       2. templates format and location
//       3. what to generate
//    2. parse specification
//     1. choose and load parser format
//     2. parse into array/load
//     3. format check
//   3.a. new - writing
//     1. using spec data, write C files
//     2. using spec data, write test files
//     3. using spec data, write doc files
//   3.b. update - reading/writing
//     1. read in data, compare to spec data, write C files
//     2. read in data, compare to spec data, write test files
//     3. read in data, compare to spec data, write doc files