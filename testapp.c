//
// Created by arthur on 24/04/24.
//
#include "user_memory_api.h"

typedef struct employee_{
    char name[32];
    uint32_t employee_id;
} employee_t;

typedef struct student_ {
    char name[32];
    uint32_t  roll_number;
    uint32_t  marks_math;
    uint32_t  marks_phys;
    struct student_ *next;
} student_t;

int main(int argc, char **argv){
    mm_init();
    MM_REG_STRUCT(employee_t);
    MM_REG_STRUCT(student_t);
    return 0;
}
