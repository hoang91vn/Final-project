#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
namespace matplot {
    static std::vector<std::vector<double>> lines;
    inline void figure(bool visible=true) { lines.clear(); }
    inline void plot(const std::vector<double>& y, const std::string& style="") {
        lines.push_back(y);
    }
    inline void hold(bool) {}
    inline void legend(const std::vector<std::string>&) {}
    inline void save(const std::string& filename) {
        std::ofstream f("/tmp/plot.csv");
        size_t nmax=0; for(auto& l:lines) nmax=std::max(nmax,l.size());
        for(size_t i=0;i<nmax;++i){
            for(size_t j=0;j<lines.size();++j){
                double v=(i<lines[j].size()?lines[j][i]:0); f<<v; if(j+1<lines.size()) f<<","; }
            f<<"\n";
        }
        f.close();
        std::ofstream py("/tmp/plot.py");
        py<<"import matplotlib.pyplot as plt\n";
        py<<"import csv,sys\n";
        py<<"rows=list(csv.reader(open('/tmp/plot.csv')))\n";
        py<<"data=list(zip(*rows))\n";
        py<<"for d in data: plt.plot([float(x) for x in d])\n";
        py<<"plt.savefig('"<<filename<<"')\n";
        py.close();
        std::system("python3 /tmp/plot.py");
    }
    inline void close(){}
}
