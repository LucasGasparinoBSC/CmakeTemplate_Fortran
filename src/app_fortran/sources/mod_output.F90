module mod_output
    contains
    subroutine Message(msg)
        implicit none
        character(len=*), intent(in) :: msg
        write(*,10) "-- APP_F90 : ", msg
10      format(A,A)
    end subroutine Message
end module mod_output