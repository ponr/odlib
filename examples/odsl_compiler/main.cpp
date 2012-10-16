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
    using std::string;
    using od::graphics::odsl::ShaderCompiler;

    ShaderCompiler compiler;

    if(argc < 2)
    {
        cerr << "Error, no parameter given" << endl;
        return EXIT_FAILURE;
    }

    ifstream inputfile;
    inputfile.open(argv[1]);

    if(!inputfile.is_open())
    {
        cerr << "Error, file '" << argv[1] << "' could not be opened" << endl;
        return EXIT_FAILURE;
    }

    inputfile.seekg(0, std::ios::end);
    int length = inputfile.tellg();
    inputfile.seekg(0, std::ios::beg);

    char * buf = new char[length];
    inputfile.read(buf, length);

    string shadersource(buf, 0, length);

    delete[] buf;

    inputfile.close();

    // Compiler shader source read from file
    compiler.setSource(shadersource);
    compiler.compile();
    //cout << compiler.getCompilationError() << endl;


    return EXIT_SUCCESS;
}
