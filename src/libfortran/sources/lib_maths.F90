module lib_maths
    contains
    pure subroutine vecAdd(n,a,b,c)
        implicit none
        integer(8), intent(in)  :: n
        real(8)   , intent(in)  :: a(n), b(n)
        real(8)   , intent(out) :: c(n)
        integer(8)              :: i
#ifdef USE_ACC
        !$acc parallel loop
#endif
        do i = 1, n
            c(i) = a(i) + b(i)
        end do
    end subroutine vecAdd
end module lib_maths