program app_fortran
    use mod_output
    implicit none
    character(len=20) :: msg
    msg = 'Hello World'
    call Message(msg)
end program app_fortran