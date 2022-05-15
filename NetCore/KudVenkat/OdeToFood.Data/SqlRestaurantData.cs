using OdeToFood.Core;
using System.Collections.Generic;
using System.Linq;
namespace OdeToFood.Data
{
    public class SqlRestaurantData : IRestaurantData
    {
        public SqlRestaurantData(OdeToFoodDBContext dbContext)
        {
            DbContext = dbContext;
        }

        public OdeToFoodDBContext DbContext { get; }

        public Restaurants AddNewRestaurant(Restaurants newRestaurant)
        {
            DbContext.Restaurants.Add(newRestaurant);
            return newRestaurant;
        }

        public Restaurants DeleteRestaurant(int restaurantId)
        {
            Restaurants restaurantToDelete = GetRestaurantById(restaurantId);
            DbContext.Restaurants.Remove(restaurantToDelete);
            return restaurantToDelete;
        }

        public Restaurants GetRestaurantById(int restaurantId)
        {
            return DbContext.Restaurants.Find(restaurantId);
        }

        public IEnumerable<Restaurants> GetRestaurantsByName(string restaurantName)
        {
            var query = from aRestaurant in DbContext.Restaurants
                        where aRestaurant.Name.StartsWith(restaurantName) || string.IsNullOrEmpty(restaurantName)
                        orderby aRestaurant.Name
                        select aRestaurant;
            return query;
        }

        public Restaurants UpdateRestaurant(Restaurants updatedRestaurant)
        {
            var entity = DbContext.Restaurants.Attach(updatedRestaurant);
            entity.State = Microsoft.EntityFrameworkCore.EntityState.Modified;
            return updatedRestaurant;
        }

        public int Commit() 
        {
            return DbContext.SaveChanges();
        }
    }
}
