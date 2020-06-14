import store from './store';
import * as actions from './actionTypes';
import { bugAdded, bugRemoved, bugResolved } from './actionCreator';
const unsubscribe = store.subscribe(() => {
	console.log("store changed",store.getState());
});

store.dispatch(bugAdded("This is bug 1"));

store.dispatch(bugResolved(1));

store.dispatch(bugRemoved(1));

console.log(store.getState());