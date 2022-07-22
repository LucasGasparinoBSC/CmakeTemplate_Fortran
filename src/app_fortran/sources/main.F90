program app_fortran
    use mod_output
    use lib_maths
    implicit none
    integer(8), parameter              :: n = 10
    real(8), allocatable, dimension(:) :: a, b, c
    character(len=20)                  :: msg
    msg = 'Hello World'
    call Message(msg)
    allocate(a(n))
    allocate(b(n))
    allocate(c(n))
    a(:) = 1.0d0
    b(:) = 1.0d0
    call vecAdd(n,a,b,c)
    print*, c(1)
end program app_fortran