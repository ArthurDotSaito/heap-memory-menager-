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

static void mm_free_memory_page_to_kernel(void *vm_page, int units)
{
    if (munmap(vm_page, units * SYZE_PAGE_SIZE))
    {
        printf("Error: VM Page deallocation failed. Could not munmap VM page to kernel\n");
    }
}

int main(int argc, char **argv)
{
    mm_init();
    printf("VM page size = %lu\n", SYZE_PAGE_SIZE);
    void *addr_01 = mm_get_new_vm_page_from_kernel(1);
    void *addr_02 = mm_get_new_vm_page_from_kernel(1);
    printf("page 01 = %p, page 02 = %p\n", addr_01, addr_02);
    return 0;
}