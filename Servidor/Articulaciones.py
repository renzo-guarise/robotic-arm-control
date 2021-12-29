class Articulacion():

    numArticulaciones = 0
    unidadRot = "deg"
    unidadTras = "mm"
    unidadTiempo = "seg"

    def __init__(self, tipo = "R", qlimMin=-180,qlimMax=180,velocidadMin=0,velocidadMax=100):

        self.tipo = tipo #por defecto son de rotacion, sino T son de Traslacion
        self.LimMin = qlimMin
        self.LimMax = qlimMax
        self.q = 0          # --- R --- --- T ---
        # deg, rad, mm, cm, in

        self.estadoArticulacion = "Detenido" #Moviendo

        self.veloc_q = (velocidadMax+velocidadMin)/2 #unit_q / seg
        self.velocMin = velocidadMin #unit_q / seg
        self.velocMax = velocidadMax #unit_q / seg
        self.q_list=[]
        Articulacion.numArticulaciones += 1

    def moverQ(self, newQ=0):
        if self.verificarLimites(self.q+newQ):
            #se mueve
            self.q+=newQ
            self.tiempo = newQ / self.veloc_q
            self.q_list.append(self.q)
            return self.tiempo # en seg
        else:
            print("Fuera de rango")
            return -1 #error de que no se pudo mover
    
    def setQ(self,newQ):
        if self.verificarLimites(newQ):
            #se mueve
            self.q=newQ
            self.tiempo = 1#newQ / self.veloc_q
            self.q_list.append(self.q)
            return self.tiempo # en seg
        else:
            print("Fuera de rango")
            return -1 #error de que no se pudo mover
            
    def setVQ(self,newVQ):
        if self.verificarLimitesV(newVQ):
            #se mueve
            self.veloc_q=newVQ
            return 1 # en seg
        else:
            print("Fuera de rango")
            return -1 #error de que no se pudo mover

    def obtenerQ(self):
        return self.q
    def obtenerVQ(self):
        return self.veloc_q

    def verificarLimites(self,coordenada):
        if coordenada>=self.LimMin and coordenada <= self.LimMax:
            return True
        else:
            return False

    def verificarLimitesV(self,vq):
        if vq>=self.velocMin and vq <= self.velocMax:
            return True
        else:
            return False