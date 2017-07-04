//Copyright 2017, Erostin Lushka, All rights reserved.

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;
using ist = istreambuf_iterator<char>;
using ost = ostreambuf_iterator<char>;

int main()
{
    string locations[3] = {"S:\\Program Files (x86)/Adobe Photoshop CC 2017/AMT/application.xml",
                           "S:\\Program Files (x86)/Acrobat DC/Acrobat/AMT/application.xml",
                           "S:\\Program Files (x86)/Adobe Lightroom/AMT/application.xml" };

    for(int k=0; k < 3; k++) {
    string s;
    string numb;
    ifstream file(locations[k]);
    ofstream fileout("fileout.txt"); //Output file

    if(file.is_open()) {
        while(!file.eof()) {
            getline(file, s);
            for(int i=0; i<s.length(); i++) {
                if((isdigit(s[i-1])==false) && isdigit(s[i]) && isdigit(s[i+1]) && isdigit(s[i+2]) && isdigit(s[i+3]) && isdigit(s[i+4])
                    && isdigit(s[i+5]) && isdigit(s[i+6]) && isdigit(s[i+7]) && isdigit(s[i+8])
                    && isdigit(s[i+9])  && isdigit(s[i+10])  && isdigit(s[i+11])  && isdigit(s[i+12])  && isdigit(s[i+13])  && isdigit(s[i+14])
                    && isdigit(s[i+15])  && isdigit(s[i+16])  && isdigit(s[i+17])  && isdigit(s[i+18])  && isdigit(s[i+19])  && isdigit(s[i+20])
                    && isdigit(s[i+21])  && isdigit(s[i+22])  && isdigit(s[i+23]) && (isdigit(s[i+24])==false)) {
                                            fileout << s[i] << s[i+1] << s[i+2] << s[i+3] << s[i+4] << s[i+5] << s[i+6] << s[i+7] << s[i+8] << s[i+9]
                                                    << s[i+10] << s[i+11] << s[i+12] << s[i+13] << s[i+14] << s[i+15] << s[i+16] << s[i+17] << s[i+18]
                                                    << s[i+19] << s[i+20] << s[i+21] << s[i+22] << s[i+23];
                                                                            }
                                            }
                            }
                        }
    fileout.close();

    ifstream fileiny ("fileout.txt");
    if(fileiny.is_open()) {
        getline(fileiny, numb);
        cout << numb << endl;
    }
    cout << numb[23] << endl;

    string newnumb = numb.substr (21,23);

    long int var1;

    var1 = strtol(newnumb.c_str(),0,10);

    cout << "\nThis is the integer: " << var1 << endl;

    long int var2;

    var2 = var1 + 1;

    cout << "\nThis is the new integer: " << var2 << endl;

    stringstream ss;
    ss << var1;
    string strReplace = ss.str();
    cout << "This is strReplace: " << strReplace << endl;
    stringstream sp;
    sp << var2;
    string strNew = sp.str();
    cout << "This is strNew: " << strNew << endl;

    numb.replace(21, 3, strNew);

    cout << "This is final: " << numb << endl;

    auto from = strReplace, to = strNew;
    for(auto filename : {locations[k]}) {
        ifstream infile {filename};
        string content {ist {infile}, ist{}};
        infile.close();
        ofstream outfile {filename};
        regex_replace(ost {outfile}, begin(content), end(content), regex {from}, to);
    }

    }
	return 0;
}
