# frozen_string_literal: true

require 'test_helper'

class OpportunitiesControllerTest < ActionDispatch::IntegrationTest
  setup do
    @opportunity = opportunities(:one)
  end

  test 'should get index' do
    get opportunities_url
    assert_response :success
  end

  test 'should get new' do
    get new_opportunity_url
    assert_response :success
  end

  test 'should create opportunity' do
    assert_difference('Opportunity.count') do
      post opportunities_url, params: { opportunity: { address: @opportunity.address, city: @opportunity.city, description: @opportunity.description, email: @opportunity.email, frequency: @opportunity.frequency, name: @opportunity.name, state: @opportunity.state, transportation: @opportunity.transportation, zipcode: @opportunity.zipcode } }
    end

    assert_redirected_to opportunity_url(Opportunity.last)
  end

  test 'should show opportunity' do
    get opportunity_url(@opportunity)
    assert_response :success
  end

  test 'should get edit' do
    get edit_opportunity_url(@opportunity)
    assert_response :success
  end

  test 'should update opportunity' do
    patch opportunity_url(@opportunity), params: { opportunity: { address: @opportunity.address, city: @opportunity.city, description: @opportunity.description, email: @opportunity.email, frequency: @opportunity.frequency, name: @opportunity.name, state: @opportunity.state, transportation: @opportunity.transportation, zipcode: @opportunity.zipcode } }
    assert_redirected_to opportunity_url(@opportunity)
  end

  test 'should destroy opportunity' do
    assert_difference('Opportunity.count', -1) do
      delete opportunity_url(@opportunity)
    end

    assert_redirected_to opportunities_url
  end
end
