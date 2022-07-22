program app_fortran
    use mod_output
    use lib_maths
#ifndef NO_MPI
    use mpi
#endif
    implicit none
    integer(4)                         :: ierr
    integer(4)                         :: numRanks, rank
    integer(8), parameter              :: n = 10
    real(8), allocatable, dimension(:) :: a, b, c
    character(len=20)                  :: msg
#ifndef NO_MPI
    call mpi_init(ierr)
    call mpi_comm_size(mpi_comm_world, numRanks, ierr)
    call mpi_comm_rank(mpi_comm_world, rank, ierr)
    print*, 'numRanks = ', numRanks, ' rank = ', rank
#endif
    msg = 'Hello World'
    call Message(msg)
    allocate(a(n))
    allocate(b(n))
    allocate(c(n))
    a(:) = 1.0d0
    b(:) = 1.0d0
    call vecAdd(n,a,b,c)
    print*, c(1)
    deallocate(a)
    deallocate(b)
    deallocate(c)
#ifndef NO_MPI
    call mpi_finalize(ierr)
#endif
end program app_fortran