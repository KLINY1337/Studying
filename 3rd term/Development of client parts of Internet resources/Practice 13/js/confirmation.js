function confirmation() {
  let resultat = confirm("Вы хотите перейти по ссылке?");
  if (resultat === true) {
    location.href = "zad8.html";
  } else {
    Event.preventDefault();
  }
  //let resultat = confirm("Вы хотите перейти по ссылке?");
  //location.href = "zad8.html";
  //if (!resultat) {
  //  console.log("hello");
  // }
}
