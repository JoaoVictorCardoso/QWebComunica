var wSocket = new WebSocket('ws://localhost:9000');

wSocket.onopen = function(evt){
    alert("CONECTOU");
};
wSocket.onclose = function(evt){
    alert("ENCERRADO");
};
wSocket.onmessage = function(evt){
    alert(evt.value);
};
wSocket.onerror = function(evt){
    alert("tem um erro");
};

function enviar(){
    var txt = document.getElementById("textotag");
    var valor= txt.value;
    wSocket.send(valor);
};
