#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <od/graphics/odsl/ShaderCompiler.hpp>

int main(int argc, char** argv)
{
    using std::cout;
    using std::cerr;
    using std::endl;
    using std::ifstream;
    using std::istreambuf_iterator;
    using std::string;
    using od::graphics::odsl::ShaderCompiler;

    // Check parameter count
    if(argc < 2)
    {
        cerr << "Error, no parameter given" << endl;
        return EXIT_FAILURE;
    }

    // Open file given in parameter
    ifstream inputfile;
    inputfile.open(argv[1]);

    // Check if opened
    if(!inputfile.is_open())
    {
        cerr << "Error, file '" << argv[1] << "' could not be opened" << endl;
        return EXIT_FAILURE;
    }

    // Don't skip white space
    inputfile.unsetf(std::ios::skipws);

    // Read file to string using istreambuf iterators
    string shadersource(istreambuf_iterator <char> (inputfile.rdbuf()),
                        istreambuf_iterator <char> () );
    inputfile.close();

    // Compile shader source read from file
    ShaderCompiler compiler;
    compiler.setSource(shadersource);
    compiler.compile();

    return EXIT_SUCCESS;
}
