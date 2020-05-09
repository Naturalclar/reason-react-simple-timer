[%bs.raw {|require('./game.css')|}];

type action = 
| Tick;

type state = {count:int};

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(
    (state,action)=> switch(action){
    | Tick => {count: state.count + 1}},
    {count:0}  
  );
  React.useEffect0(()=>{
    let timerId = Js.Global.setInterval(()=>dispatch(Tick),1000);
    Some(()=>Js.Global.clearInterval(timerId));
  });
  <div>
    <h1> {React.string(string_of_int(state.count))}</h1>
  </div>
}