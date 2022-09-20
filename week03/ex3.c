#include<stdio.h>
#include<stdlib.h>
#include <string.h>


struct Directory;
struct File;

struct File{
    int id;
    
    char name[128];
    char data[2048];
    unsigned int size;
    
    struct Directory * directory;// The parent directory
};

struct Directory{
    int nf;
    int nd;
    
    char path[4096];
    struct Directory* directories[32];
    struct File *files[512];
};

 

// Operations on files
void add_to_file(struct File *file, const char * content);
void append_to_file(struct File *file, const char * content);
void pwd_file(struct File * file);


// Operations on directories
void add_file(struct File* file, struct Directory *dir);
void add_dir(struct Directory *dir1, struct Directory *dir2); // given to you

// Helper functions
void show_dir(struct Directory *dir);
void show_file(struct File *file);
void show_file_detailed(struct File *file);

int main(){
    
    char content1[] = "int printf(const char * format, ...);";
    char content2[] = "int main(){printf('Hello World');}";
    char content3[] = "//This is a comment in C language";
    char content4[] = "Bourne Again Shell!";
    
    struct Directory home, bin, root;
    
    root.nd = 0;
    root.nf = 0;
    
    // Add subdirectories
    add_dir(&home, &root);
    add_dir(&bin, &root);
    
    struct File bash, ex31, ex32;
    
    memcpy(bash.name, "bash", 4);
    memcpy(ex31.name, "ex31", 4);
    memcpy(ex32.name, "ex32", 4);

    memcpy(bin.path, "/bin", 4);
    add_file(&bash, &bin);
    
    memcpy(home.path, "/home", 5);
    add_file(&ex32, &home);
    add_file(&ex31, &home);
    
    add_to_file(&ex32, content3);
    add_to_file(&bash, content4);
    
    add_to_file(&ex31, content1);
    append_to_file(&ex31, content2);

    memcpy(root.path, "/", 1);
    
    show_dir(&root);
    show_file_detailed(&bash);
    show_file_detailed(&ex31);
    show_file_detailed(&ex32);

    pwd_file(&bash);
    pwd_file(&ex31);
    pwd_file(&ex32);
   
    return EXIT_SUCCESS;
}

// Helper functions

// Displays the content of the Directory dir
void show_dir(struct Directory *dir){
    printf("\nDIRECTORY\n");
    printf(" path: %s\n", dir->path);
    printf(" files:\n");
    printf("    [ ");
    printf("%d", dir->nf);
    for (int i = 0; i < dir->nf; i++){
        show_file(dir->files[i]);
    }
    printf("]\n");
    printf(" directories:\n");
    printf("    { ");
    
    for (int i = 0; i < dir->nd; i++){
        show_dir(dir->directories[i]);
    }
    printf("}\n");
}

// Prints the name of the File file
void show_file(struct File *file){
    printf("%s ", file->name);
}

// Shows details of the File file
void show_file_detailed(struct File *file){
    printf("\nFILE\n");
    printf(" id: %d\n", file->id);
    printf(" name: %s\n", file->name);
    printf(" size: %u\n", file->size);
    printf(" data:\n");
    printf("    [ %s ]\n", file->data);
}



// Implementation: Operations on files

// Adds the content to the File file
void add_to_file(struct File *file, const char * content) {
    int contentLength = strlen(content);
    memcpy(file->data, content, contentLength);
    file->size = contentLength;
}

// Appends the content to the File file
void append_to_file(struct File *file, const char * content) {
	char *ptr = file->data + file->size;
    strcpy(ptr, content);
    file->size += strlen(content);
}

// Prints the path of the File file
void pwd_file(struct File * file) {
    printf("the path for the %s file is %s\n",file->name, file->directory->path);
}

// Implementation: Operations on directories
// Adds the File file to the Directory dir
void add_file(struct File* file, struct Directory *dir) {
    file->directory = dir;
	dir->files[dir->nf++]=file;
}
// Given to you
// Adds the subdirectory dir1 to the directory dir2
void add_dir(struct Directory *dir1, struct Directory *dir2){
	if ( dir1 && dir2 ){
		dir2->directories[dir2->nd++] = dir1;
	}
}



