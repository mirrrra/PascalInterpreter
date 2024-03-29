#include "driver.hh"
#include "parser.hh"



Driver::Driver() :
        trace_parsing(false),
        trace_scanning(false),
        location_debug(false),
        scanner(*this), parser(scanner, *this) {
}


int Driver::parse(const std::string& f) {
    file = f;
    location.initialize(&file);
    scan_begin();
    parser.set_debug_level(trace_parsing);
    int res = parser();
    program->run();
    scan_end();
    return res;
}

void Driver::scan_begin() {
    scanner.set_debug(trace_scanning);
    if (file.empty () || file == "-") {
    } else {
        stream.open(file);
        //std::cout << file << std::endl;
        scanner.yyrestart(&stream);
    }
}

void Driver::scan_end()
{
    stream.close();
}