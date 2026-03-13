const vermelho = document.getElementById("vermelho")
const amarelo = document.getElementById("amarelo")
const verde = document.getElementById("verde")

const ligar = document.getElementById("Ligar")
const desligar = document.getElementById("Desligar")

const lento = document.getElementById("lento")
const normal = document.getElementById("normal")
const rapido = document.getElementById("rapido")

let intervalo
let estado = "vermelho"

let tempoVermelho = 3000
let tempoVerde = 3000
let tempoAmarelo = 1000

function apagar(){
    vermelho.className = "luz"
    amarelo.className = "luz"
    verde.className = "luz"
}

function ciclo(){

    if(estado === "vermelho"){
        apagar()
        verde.classList.add("verde")
        estado = "verde"
        intervalo = setTimeout(ciclo, tempoVerde)
    }

    else if(estado === "verde"){
        apagar()
        amarelo.classList.add("amarelo")
        estado = "amarelo"
        intervalo = setTimeout(ciclo, tempoAmarelo)
    }

    else{
        apagar()
        vermelho.classList.add("vermelho")
        estado = "vermelho"
        intervalo = setTimeout(ciclo, tempoVermelho)
    }

}

function iniciar(){
    estado = "vermelho"
    vermelho.classList.add("vermelho")
    intervalo = setTimeout(ciclo, tempoVermelho)
}

function parar(){
    clearTimeout(intervalo)
    apagar()
}

ligar.addEventListener("click", iniciar)
desligar.addEventListener("click", parar)

lento.addEventListener("click", ()=>{
    tempoVermelho = 2000
    tempoVerde = 1000
    tempoAmarelo = 2000
})

normal.addEventListener("click", ()=>{
    tempoVermelho = 1000
    tempoVerde = 500
    tempoAmarelo = 1000
})

rapido.addEventListener("click", ()=>{
    tempoVermelho = 100
    tempoVerde = 50
    tempoAmarelo = 100
})