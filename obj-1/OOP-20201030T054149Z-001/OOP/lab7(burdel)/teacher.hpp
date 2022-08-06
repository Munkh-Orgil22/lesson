

#ifndef teacher_hpp
#define teacher_hpp

#include <stdio.h>
class teacher{
private:
    char *id;
public:
    char *name;
    char *title;
    teacher( );
    ~teacher( );
    teacher(char *nam, char *tit, char *ida  );
    void setName(char stn[]);
    void setTitle(char stn[]);
    void setId(char stn[]);
    char* getName();
    char* getTitle();
    char* getId();
};
#endif /* teacher_hpp */
