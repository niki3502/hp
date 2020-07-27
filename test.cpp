#include <htslib/faidx.h>
#include <cassert>

int main(int argc,char **argv){
  if(argc==1){
    fprintf(stderr,"Supply input fasta\n");
    return 0;
  }
  char *fain = argv[1];
  faidx_t *fai = NULL;
  fprintf(stderr,"input fasta is: %s\n",fain);

  fai  = fai_load(fain);
  assert(fai!=NULL);

  assert(faidx_nseq(fai)==1);//file should only contain one entry

  const char *name = faidx_iseq(fai,0);
  int name_len = faidx_seq_len(fai,name);
  fprintf(stderr,"name: %s length: %d\n",name,name_len);

  char *data = fai_fetch(fai,name,&name_len);
  for(int i=0;i<name_len;i++)
    fprintf(stdout,"%d\t%c\n",i,data[i]);
  return 0;
}
