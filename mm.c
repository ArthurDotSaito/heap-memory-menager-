#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include <sys/mman.h>

static size_t SYZE_PAGE_SIZE = 0;

void mm_init()
{
    SYZE_PAGE_SIZE = getpagesize();
}

static void *mm_get_new_vm_page_from_kernel(int units)
{
    char *vm_page = mmap(0, units * SYZE_PAGE_SIZE, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANON | MAP_PRIVATE, 0, 0);

    if (vm_page == MAP_FAILED)
    {
        printf("Error: VM Page allocation failed\n");
        return NULL;
    }

    memset(vm_page, 0, units * SYZE_PAGE_SIZE);
    return (void *)vm_page;
}