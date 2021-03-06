#include "../config_params.h"
#include "../convertor.h"

Config_params* Config_params::instance = NULL;

int main(int argc, char **argv){
//    PetscInitialize(&argc, &argv, NULL, NULL);
    PetscInitialize(NULL, NULL, NULL, NULL);
    //read XML parameters
    Config_params::getInstance()->read_params("./params.xml", argc, argv, Config_params::convert_files);

    Mat A;
    Vec lbl;
    std::string str_in_fname = Config_params::getInstance()->get_ds_path()
                        + Config_params::getInstance()->get_ds_name();
    Convertor cv;
    cv.Libsvm_file_to_PETSc_format( str_in_fname, A,lbl);

    std::cout << "Convert LibSVM to PETSc binary format finished successfully!\n";
    PetscFinalize();
    return 0;
}









//#include "../convertor.h"
//#include <iostream>

//int main(int argc, char **argv)
//{
//    PetscInitialize(NULL, NULL, NULL, NULL);
//    Mat A;
//    Vec lbl;

////    char           in_filename[PETSC_MAX_PATH_LEN];
////    PetscBool      flg;
//////    PetscOptionsGetString(NULL,"-i",in_filename,sizeof(in_filename),&flg);     //PETSc version 3.6 and earlier
////    PetscOptionsGetString(NULL,NULL,"-i",in_filename,sizeof(in_filename),&flg);  //PETSc version 3.7
////    if(!flg){
////        std::cout << "please specify the input file name using -i parameter!" << std::endl;
////        exit(1);
////    }
////    std::string str_in_fname (in_filename);

////    PetscOptionsGetString(NULL,NULL,"-o",out_filename,sizeof(out_filename),&flg);
////    if(flg){
////        str_out_fname {str_in_fname};
////    }



//    Convertor cv;
////    cv.Libsvm_file_to_PETSc_format("./data/heart_scale", A,lbl);
//    cv.Libsvm_file_to_PETSc_format( str_in_fname, A,lbl);

////    printf("[libsvm_PETSc] input data:\n");                                               //$$debug
////    MatView(A,PETSC_VIEWER_STDOUT_WORLD);                                //$$debug

////    printf("[libsvm_PETSc] input label:\n");                                               //$$debug
////    VecView(lbl,PETSC_VIEWER_STDOUT_WORLD);                                //$$debug

////    MatDestroy(&A);
////    VecDestroy(&lbl);

//    PetscFinalize();
//    return 0;
//}

