import * as actions from './actionTypes';

let lastId = 0;

export default function reducer(state = [], action){
	if(action.type === actions.BUG_ADDED){
		return [
			...state,
			{
				id: ++lastId,
				description: action.payLoad.description,
				resolved: false
			}
		]
	}
	else if(action.type === actions.BUG_REMOVED){
		return state.filter(bug=> bug.id !== action.payLoad.id);
 	}
 	else if(action.type === actions.BUG_RESOLVED){
 		return state.map(bug=> bug.id !== action.payLoad.id ? bug : {...bug, resolved: true});
 	}
 	return state;
}