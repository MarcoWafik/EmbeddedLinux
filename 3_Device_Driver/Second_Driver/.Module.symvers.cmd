cmd_/home/marco/EmbeddedLinux/3_Device_Driver/Second_Driver/Module.symvers := sed 's/\.ko$$/\.o/' /home/marco/EmbeddedLinux/3_Device_Driver/Second_Driver/modules.order | scripts/mod/modpost -m -a  -o /home/marco/EmbeddedLinux/3_Device_Driver/Second_Driver/Module.symvers -e -i Module.symvers   -T -