const vermelho = document.getElementById("vermelho")
const amarelo = document.getElementById("amarelo")
const verde = document.getElementById("verde")

const ligar = document.getElementById("Ligar")
const desligar = document.getElementById("Desligar")

let intervalo

function apagar(){
    vermelho.className = "luz"
    amarelo.className = "luz"
    verde.className = "luz"
}

function iniciar(){

    vermelho.classList.add("vermelho")

    intervalo = setInterval(()=>{

        if(vermelho.classList.contains("vermelho")){
            apagar()
            verde.classList.add("verde")
        }

        else if(verde.classList.contains("verde")){
            apagar()
            amarelo.classList.add("amarelo")

            setTimeout(()=>{
                apagar()
                vermelho.classList.add("vermelho")
            },2000)
        }

        else{
            apagar()
            vermelho.classList.add("vermelho")
        }

    },5000)

}

function parar(){
    clearInterval(intervalo)
    apagar()
}

ligar.addEventListener("click", iniciar)
desligar.addEventListener("click", parar)