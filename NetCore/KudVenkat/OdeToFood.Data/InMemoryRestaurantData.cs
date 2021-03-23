using OdeToFood.Core;
using System;
using System.Collections.Generic;

namespace OdeToFood.Data
{
    public class InMemoryRestaurantData : IRestaurantData
    {
        List<Restaurants> listOfRestaurants;
        public InMemoryRestaurantData()
        {
            listOfRestaurants = new List<Restaurants>()
            {
                new Restaurants{ Name="First", Id = 1, Cuisine = CuisineTypes.Indian, Location = "1st Phase"},
                new Restaurants{Id = 2, Name = "Second", Cuisine = CuisineTypes.Local, Location = "2nd Phase"},
                new Restaurants{Id = 3, Name = "Third", Cuisine = CuisineTypes.None, Location = "3rd Phase"},
                new Restaurants{Id = 4, Name = "fourth", Cuisine = CuisineTypes.Mexican, Location = "4th Phase"}
            };
        }
        IEnumerable<Restaurants> IRestaurantData.GetRestaurantsByName(string restaurantName)
        {
            if(string.IsNullOrEmpty(restaurantName)) {
                restaurantName = "";
            }
            return listOfRestaurants.FindAll(x => x.Name.Contains(restaurantName) || string.IsNullOrEmpty(restaurantName));
        }

        Restaurants IRestaurantData.GetRestaurantById(int restaurantId)
        {
            return listOfRestaurants.Find(x => x.Id == restaurantId);
        }

        public Restaurants UpdateRestaurant(Restaurants updatedRestaurant)
        {
            Restaurants restaurantToBeUpdated = listOfRestaurants.Find(x => x.Id == updatedRestaurant.Id);
            listOfRestaurants.Remove(restaurantToBeUpdated);
            restaurantToBeUpdated = updatedRestaurant;
            listOfRestaurants.Add(restaurantToBeUpdated);
            return listOfRestaurants.Find(x => x.Id == updatedRestaurant.Id);
        }

        public Restaurants AddNewRestaurant(Restaurants newRestaurant)
        {
            newRestaurant.Id = listOfRestaurants.Count + 1;
            listOfRestaurants.Add(newRestaurant);
            return listOfRestaurants.Find(x => x.Id == newRestaurant.Id);
        }

        public Restaurants DeleteRestaurant(int restaurantId)
        {
            var returnValue = listOfRestaurants.Find(x => x.Id == restaurantId);
            listOfRestaurants.Remove(listOfRestaurants.Find(x => x.Id == restaurantId));
            return returnValue;
        }

        public int Commit()
        {
            return 0;
        }
    }
}
