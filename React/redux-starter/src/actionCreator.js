import * as actions from './actionTypes';

export function bugAdded(bug_description){
	return {
		type: actions.BUG_ADDED,
		payLoad:{
			description: bug_description
		}
	}
}

export function bugRemoved(bug_id){
	return {
		type: actions.BUG_REMOVED,
		payLoad:{
			id: bug_id
		}
	}
}

export function bugResolved(bug_id){
	return{
		type: actions.BUG_RESOLVED,
		payLoad:{
			id: bug_id
		}
	}
}
