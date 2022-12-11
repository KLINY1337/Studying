let timerId = setInterval(() => {
  let counter = document.getElementById("notification-count");
  counter.textContent = String(parseInt(counter.textContent) + 1);
  let list = document.getElementById("menu2");
  let note = document.createElement("li");
  note.textContent = "Notification " + counter.textContent;
  list.appendChild(note);
}, 3000);

function handleNotification() {
  console.log("hello");
  clearInterval(timerId);

  setTimeout((timerId) => {
    timerId = setInterval(() => {
      let counter = document.getElementById("notification-count");
      counter.textContent = String(parseInt(counter.textContent) + 1);
      let list = document.getElementById("menu2");
      let note = document.createElement("li");
      note.textContent = "Notification " + counter.textContent;
      list.appendChild(note);
    }, 3000);
  }, 10000);
}
