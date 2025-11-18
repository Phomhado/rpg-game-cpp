const logEl = document.getElementById("log");
const statusEl = document.getElementById("status");
const formEl = document.getElementById("player-form");
const choiceButtons = document.querySelectorAll("#choices button");

let engine = null;

function appendLog(text) {
  logEl.textContent += `${text}\n\n`;
  logEl.scrollTop = logEl.scrollHeight;
}

function setStatus(text) {
  statusEl.textContent = text;
}

function getField(name) {
  return formEl.elements.namedItem(name).value;
}

function disableUI(disabled) {
  choiceButtons.forEach((btn) => (btn.disabled = disabled));
  [...formEl.elements].forEach((el) => (el.disabled = disabled));
}

function loadStartingScene() {
  if (!engine) return;
  const scene = engine.get_starting_scene();
  appendLog(scene);
}

function wireChoices() {
  choiceButtons.forEach((button) => {
    button.addEventListener("click", () => {
      if (!engine) return;
      const choice = Number(button.dataset.choice);
      const text = engine.resolve_starting_choice(choice);
      appendLog(text);
    });
  });
}

function mountModule() {
  if (typeof createRpgModule !== "function") {
    setStatus("game.js not found. Build the wasm bundle first.");
    disableUI(true);
    return;
  }

  setStatus("Compiling WebAssembly...");
  createRpgModule().then((Module) => {
    engine = {
      set_player: Module.cwrap("set_player", null, [
        "string",
        "string",
        "string",
        "number",
        "number",
        "number",
      ]),
      get_player_summary: Module.cwrap("get_player_summary", "string", []),
      get_starting_scene: Module.cwrap("get_starting_scene", "string", []),
      resolve_starting_choice: Module.cwrap("resolve_starting_choice", "string", [
        "number",
      ]),
    };

    setStatus("WebAssembly loaded. Create a character to begin.");
    disableUI(false);
    loadStartingScene();
  });
}

function wireForm() {
  formEl.addEventListener("submit", (event) => {
    event.preventDefault();
    if (!engine) return;

    const name = getField("name");
    const gender = getField("gender");
    const playerClass = getField("class");
    const strength = Number(getField("strength"));
    const charisma = Number(getField("charisma"));
    const intelligence = Number(getField("intelligence"));

    engine.set_player(name, gender, playerClass, strength, charisma, intelligence);

    const summary = engine.get_player_summary();
    appendLog(summary);
    loadStartingScene();
  });
}

disableUI(true);
wireForm();
wireChoices();
mountModule();
