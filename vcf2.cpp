#include <iostream>
#include <stdexcept>
#include <htslib/vcf.h>
#include <string>
#include <cmath>


float pltoln(int32_t val) {
    return log(pow(10.0, -0.1 * val));
}
int usage() {
    std::cerr << "Usage: ./test_htslib_vcfparser example.vcf" << std::endl;
    return 1;
}

int main(int argc, char* argv[]) {

	int *pl = NULL;
 	int npl_arr = 0;
 	int npl = 0;

 	int ngt_arr = 0;
  	int ngt     = 0;
  	int *gt     = NULL;
  	int nad_arr = 0;
  	int nad     = 0;
  	int *ad     = NULL;

    if(argc == 2) {
        htsFile *inf = NULL;
        bcf_hdr_t *hdr = NULL;
        bcf1_t *rec = bcf_init();
        inf = bcf_open(argv[1], "r");
        if(inf == NULL) {
            throw std::runtime_error("Unable to open file.");
        }
        hdr = bcf_hdr_read(inf);
        if(hdr == NULL) {
            throw std::runtime_error("Unable to read header.");
        }
        std::cout << "chromosome\tposition\tPL" << std::endl;
        while(bcf_read(inf, hdr, rec) == 0) {
        	// ngt = bcf_get_format_int32(hdr, rec, "GT", &gt, &ngt_arr);

        	// std::string c_gt="0/0";
         //  if(gt[0]==2 && gt[1]==4) c_gt="0/1";
         //  if(gt[0]==4 && gt[1]==4) c_gt="1/1";
         //  if(gt[0]==2 && gt[1]==5) c_gt="0|1";
         //  if(gt[0]==4 && gt[1]==5) c_gt="1|1";
         //  if(gt[0]==2 && gt[1]==3) c_gt="0|0";
         //  if(gt[0]==4 && gt[1]==3) c_gt="1|0";

        	npl = bcf_get_format_int32(hdr, rec, "PL", &pl, &npl_arr);

            std::cout << bcf_hdr_id2name(hdr, rec->rid) << "\t" <<
                          rec->pos << "\t";
            for(int i =0;i<npl_arr;i++)
            	std::cout << pl[i]<< "\t";
            	std::cout << "\n";
            std::cout << "\t\tGL\t";
            for(int i =0;i<npl_arr;i++)
            	std::cout << pltoln(pl[i])<< "\t";
            std::cout << "\n";
        //                  rec->qual << "\t" <<
        //                  std::endl;
        // }

        }
        bcf_hdr_destroy(hdr);
        bcf_destroy(rec); 
        bcf_close(inf);
    } else {
        return usage();
    }
    return 0;
}
